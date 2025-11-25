#!/bin/bash

# =============================================================================
# AUTOCOMMIT SCRIPT - Bootcamp Arduino Repository
# =============================================================================
#
# What?
# Automated Git commit script that stages, commits, and pushes changes
# every time it's executed (designed to run via cron every 5 minutes).
#
# For?
# - Ensure continuous backup of work in progress
# - Maintain detailed commit history with semantic messages
# - Prevent loss of work during development sessions
# - Track incremental changes in bootcamp content
#
# Impact?
# - Automatic version control without manual intervention
# - Consistent commit message format (Conventional Commits)
# - Real-time synchronization with remote repository
# - Reduced risk of losing unsaved work
#
# Usage:
#   ./autocommit.sh              # Run manually
#   crontab -e                   # Add to cron for automatic execution
#
# Cron example (every 5 minutes):
#   */5 * * * * /path/to/bc-arduino/_scripts/autocommit.sh >> /path/to/logs/autocommit.log 2>&1
#
# =============================================================================

# Configuration
REPO_DIR="/home/epti/Documents/epti-dev/bc-channel/bc-arduino"
LOG_FILE="/home/epti/Documents/epti-dev/bc-channel/bc-arduino/_scripts/logs/autocommit.log"
BRANCH="main"
REMOTE="origin"

# Colors for terminal output (disabled in cron)
if [ -t 1 ]; then
    RED='\033[0;31m'
    GREEN='\033[0;32m'
    YELLOW='\033[1;33m'
    BLUE='\033[0;34m'
    NC='\033[0m' # No Color
else
    RED=''
    GREEN=''
    YELLOW=''
    BLUE=''
    NC=''
fi

# Create logs directory if it doesn't exist
mkdir -p "$(dirname "$LOG_FILE")"

# Logging function
log() {
    local level="$1"
    local message="$2"
    local timestamp=$(date '+%Y-%m-%d %H:%M:%S')
    echo "[$timestamp] [$level] $message" >> "$LOG_FILE"
    
    case $level in
        "INFO")
            echo -e "${BLUE}[$timestamp]${NC} ${GREEN}[INFO]${NC} $message"
            ;;
        "WARN")
            echo -e "${BLUE}[$timestamp]${NC} ${YELLOW}[WARN]${NC} $message"
            ;;
        "ERROR")
            echo -e "${BLUE}[$timestamp]${NC} ${RED}[ERROR]${NC} $message"
            ;;
        *)
            echo "[$timestamp] [$level] $message"
            ;;
    esac
}

# Get commit type based on changed files
get_commit_type() {
    local files="$1"
    
    if echo "$files" | grep -qE '\.md$'; then
        echo "docs"
    elif echo "$files" | grep -qE '\.(ino|cpp|c|h)$'; then
        echo "feat"
    elif echo "$files" | grep -qE '\.(svg|png|jpg|gif)$'; then
        echo "style"
    elif echo "$files" | grep -qE '_scripts/'; then
        echo "chore"
    elif echo "$files" | grep -qE '\.gitignore|copilot-instructions'; then
        echo "chore"
    else
        echo "chore"
    fi
}

# Get commit scope based on changed files
get_commit_scope() {
    local files="$1"
    
    if echo "$files" | grep -qE 'semana-01'; then
        echo "week-01"
    elif echo "$files" | grep -qE 'semana-02'; then
        echo "week-02"
    elif echo "$files" | grep -qE 'semana-03'; then
        echo "week-03"
    elif echo "$files" | grep -qE 'semana-04'; then
        echo "week-04"
    elif echo "$files" | grep -qE 'semana-05'; then
        echo "week-05"
    elif echo "$files" | grep -qE 'semana-06'; then
        echo "week-06"
    elif echo "$files" | grep -qE 'semana-07'; then
        echo "week-07"
    elif echo "$files" | grep -qE 'semana-08'; then
        echo "week-08"
    elif echo "$files" | grep -qE 'semana-09'; then
        echo "week-09"
    elif echo "$files" | grep -qE 'semana-10'; then
        echo "week-10"
    elif echo "$files" | grep -qE '_assets'; then
        echo "assets"
    elif echo "$files" | grep -qE '_docs'; then
        echo "docs"
    elif echo "$files" | grep -qE '_scripts'; then
        echo "scripts"
    elif echo "$files" | grep -qE '\.github'; then
        echo "config"
    else
        echo "bootcamp"
    fi
}

# Generate commit description
get_commit_description() {
    local files="$1"
    local file_count=$(echo "$files" | wc -l)
    
    if [ "$file_count" -eq 1 ]; then
        local filename=$(basename "$files")
        echo "update $filename"
    else
        echo "update $file_count files"
    fi
}

# Generate commit body with What? For? Impact?
generate_commit_body() {
    local files="$1"
    local file_list=$(echo "$files" | head -10)
    local file_count=$(echo "$files" | wc -l)
    
    local body=""
    body+="What?\n"
    body+="Automated commit with changes to bootcamp content.\n\n"
    
    body+="For?\n"
    body+="Track incremental progress and maintain version history.\n\n"
    
    body+="Impact?\n"
    body+="- Files modified: $file_count\n"
    body+="- Changed files:\n"
    
    while IFS= read -r file; do
        body+="  - $file\n"
    done <<< "$file_list"
    
    if [ "$file_count" -gt 10 ]; then
        body+="  - ... and $((file_count - 10)) more files\n"
    fi
    
    body+="\n[Automated commit by autocommit.sh]"
    
    echo -e "$body"
}

# Main execution
main() {
    log "INFO" "========== Autocommit script started =========="
    
    # Change to repository directory
    if [ ! -d "$REPO_DIR" ]; then
        log "ERROR" "Repository directory not found: $REPO_DIR"
        exit 1
    fi
    
    cd "$REPO_DIR" || {
        log "ERROR" "Failed to change to repository directory"
        exit 1
    }
    
    log "INFO" "Working directory: $(pwd)"
    
    # Check if it's a git repository
    if [ ! -d ".git" ]; then
        log "ERROR" "Not a git repository: $REPO_DIR"
        exit 1
    fi
    
    # Get list of changed files (staged and unstaged)
    local changed_files=$(git status --porcelain | awk '{print $2}')
    
    if [ -z "$changed_files" ]; then
        log "INFO" "No changes detected. Nothing to commit."
        log "INFO" "========== Autocommit script finished =========="
        exit 0
    fi
    
    log "INFO" "Changes detected:"
    echo "$changed_files" | while read -r file; do
        log "INFO" "  - $file"
    done
    
    # Determine commit type and scope
    local commit_type=$(get_commit_type "$changed_files")
    local commit_scope=$(get_commit_scope "$changed_files")
    local commit_desc=$(get_commit_description "$changed_files")
    
    # Build commit message (Conventional Commits format)
    local commit_message="${commit_type}(${commit_scope}): ${commit_desc}"
    local commit_body=$(generate_commit_body "$changed_files")
    
    log "INFO" "Commit message: $commit_message"
    
    # Stage all changes
    log "INFO" "Staging all changes..."
    git add -A
    
    if [ $? -ne 0 ]; then
        log "ERROR" "Failed to stage changes"
        exit 1
    fi
    
    # Commit changes
    log "INFO" "Committing changes..."
    git commit -m "$commit_message" -m "$commit_body"
    
    if [ $? -ne 0 ]; then
        log "ERROR" "Failed to commit changes"
        exit 1
    fi
    
    log "INFO" "Commit successful"
    
    # Push to remote
    log "INFO" "Pushing to $REMOTE/$BRANCH..."
    git push "$REMOTE" "$BRANCH"
    
    if [ $? -ne 0 ]; then
        log "WARN" "Failed to push to remote. Changes committed locally."
    else
        log "INFO" "Push successful"
    fi
    
    log "INFO" "========== Autocommit script finished =========="
}

# Run main function
main "$@"
