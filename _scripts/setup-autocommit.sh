#!/bin/bash

# =============================================================================
# SETUP SCRIPT - Autocommit Configuration for Fedora 43
# =============================================================================
#
# What?
# Automated setup script to configure the autocommit system on Fedora 43.
#
# For?
# Simplify the installation process with a single command.
#
# Impact?
# - One-command setup for autocommit functionality
# - Configures either cron or systemd timer based on user preference
# - Creates necessary directories and sets permissions
#
# Usage:
#   ./setup-autocommit.sh         # Interactive mode
#   ./setup-autocommit.sh cron    # Install using cron
#   ./setup-autocommit.sh systemd # Install using systemd timer
#
# =============================================================================

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_DIR="$(dirname "$SCRIPT_DIR")"

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}"
echo "=============================================="
echo "  Autocommit Setup for Fedora 43"
echo "  Bootcamp Arduino Repository"
echo "=============================================="
echo -e "${NC}"

# Check if running on Fedora
if [ -f /etc/fedora-release ]; then
    FEDORA_VERSION=$(cat /etc/fedora-release | grep -oE '[0-9]+' | head -1)
    echo -e "${GREEN}✓ Detected Fedora $FEDORA_VERSION${NC}"
else
    echo -e "${YELLOW}⚠ Warning: This script is designed for Fedora. Proceeding anyway...${NC}"
fi

# Create logs directory
echo -e "\n${BLUE}Creating logs directory...${NC}"
mkdir -p "$SCRIPT_DIR/logs"
echo -e "${GREEN}✓ Logs directory created: $SCRIPT_DIR/logs${NC}"

# Make autocommit script executable
echo -e "\n${BLUE}Setting script permissions...${NC}"
chmod +x "$SCRIPT_DIR/autocommit.sh"
echo -e "${GREEN}✓ autocommit.sh is now executable${NC}"

# Determine installation method
METHOD="$1"

if [ -z "$METHOD" ]; then
    echo -e "\n${YELLOW}Choose installation method:${NC}"
    echo "  1) cron    - Traditional cron job (works everywhere)"
    echo "  2) systemd - Systemd timer (modern Fedora approach)"
    echo ""
    read -p "Enter choice [1/2]: " choice
    
    case $choice in
        1|cron)
            METHOD="cron"
            ;;
        2|systemd)
            METHOD="systemd"
            ;;
        *)
            echo -e "${RED}Invalid choice. Defaulting to systemd.${NC}"
            METHOD="systemd"
            ;;
    esac
fi

if [ "$METHOD" = "cron" ]; then
    echo -e "\n${BLUE}Setting up CRON job...${NC}"
    
    # Check if cronie is installed
    if ! command -v crontab &> /dev/null; then
        echo -e "${YELLOW}Installing cronie...${NC}"
        sudo dnf install -y cronie
        sudo systemctl enable --now crond
    fi
    
    # Add cron job
    CRON_LINE="*/5 * * * * $SCRIPT_DIR/autocommit.sh >> $SCRIPT_DIR/logs/autocommit.log 2>&1"
    
    # Check if already exists
    if crontab -l 2>/dev/null | grep -q "autocommit.sh"; then
        echo -e "${YELLOW}⚠ Cron job already exists. Updating...${NC}"
        crontab -l 2>/dev/null | grep -v "autocommit.sh" | crontab -
    fi
    
    # Add new cron job
    (crontab -l 2>/dev/null; echo "$CRON_LINE") | crontab -
    
    echo -e "${GREEN}✓ Cron job installed successfully${NC}"
    echo -e "\n${BLUE}Current crontab:${NC}"
    crontab -l | grep autocommit
    
elif [ "$METHOD" = "systemd" ]; then
    echo -e "\n${BLUE}Setting up SYSTEMD timer...${NC}"
    
    # Create user systemd directory
    mkdir -p ~/.config/systemd/user
    
    # Copy service and timer files
    cp "$SCRIPT_DIR/autocommit.service" ~/.config/systemd/user/
    cp "$SCRIPT_DIR/autocommit.timer" ~/.config/systemd/user/
    
    # Reload systemd
    systemctl --user daemon-reload
    
    # Enable and start timer
    systemctl --user enable --now autocommit.timer
    
    echo -e "${GREEN}✓ Systemd timer installed and started${NC}"
    echo -e "\n${BLUE}Timer status:${NC}"
    systemctl --user status autocommit.timer --no-pager
fi

echo -e "\n${GREEN}=============================================="
echo "  Setup Complete!"
echo "==============================================${NC}"
echo ""
echo -e "${BLUE}Useful commands:${NC}"

if [ "$METHOD" = "cron" ]; then
    echo "  View crontab:    crontab -l"
    echo "  Edit crontab:    crontab -e"
    echo "  View logs:       tail -f $SCRIPT_DIR/logs/autocommit.log"
    echo "  Remove job:      crontab -l | grep -v autocommit | crontab -"
else
    echo "  Timer status:    systemctl --user status autocommit.timer"
    echo "  Service status:  systemctl --user status autocommit.service"
    echo "  View logs:       journalctl --user -u autocommit.service -f"
    echo "  List timers:     systemctl --user list-timers"
    echo "  Stop timer:      systemctl --user stop autocommit.timer"
    echo "  Disable timer:   systemctl --user disable autocommit.timer"
fi

echo ""
echo -e "${YELLOW}Note: The script will run every 5 minutes and commit any changes.${NC}"
echo -e "${YELLOW}Make sure you have configured git credentials for passwordless push.${NC}"
