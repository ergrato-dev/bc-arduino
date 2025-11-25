# Scripts - Bootcamp Arduino

## 📁 Contenido

| Archivo               | Descripción                        |
| --------------------- | ---------------------------------- |
| `autocommit.sh`       | Script principal de autocommit     |
| `autocommit.cron`     | Configuración de cron job          |
| `autocommit.service`  | Unidad de servicio systemd         |
| `autocommit.timer`    | Temporizador systemd (cada 5 min)  |
| `setup-autocommit.sh` | Script de instalación automatizada |

---

## 🚀 Instalación Rápida

### Opción 1: Instalación Automatizada (Recomendada)

```bash
cd /home/epti/Documents/epti-dev/bc-channel/bc-arduino/_scripts
chmod +x setup-autocommit.sh
./setup-autocommit.sh
```

### Opción 2: Instalación Manual con Cron

```bash
# 1. Hacer el script ejecutable
chmod +x autocommit.sh

# 2. Editar crontab
crontab -e

# 3. Agregar esta línea:
*/5 * * * * /home/epti/Documents/epti-dev/bc-channel/bc-arduino/_scripts/autocommit.sh >> /home/epti/Documents/epti-dev/bc-channel/bc-arduino/_scripts/logs/autocommit.log 2>&1
```

### Opción 3: Instalación Manual con Systemd

```bash
# 1. Hacer el script ejecutable
chmod +x autocommit.sh

# 2. Copiar archivos de systemd
mkdir -p ~/.config/systemd/user
cp autocommit.service ~/.config/systemd/user/
cp autocommit.timer ~/.config/systemd/user/

# 3. Recargar y habilitar
systemctl --user daemon-reload
systemctl --user enable --now autocommit.timer
```

---

## 📋 Comandos Útiles

### Para Cron

```bash
# Ver crontab actual
crontab -l

# Editar crontab
crontab -e

# Ver logs
tail -f _scripts/logs/autocommit.log

# Eliminar job
crontab -l | grep -v autocommit | crontab -
```

### Para Systemd

```bash
# Estado del timer
systemctl --user status autocommit.timer

# Estado del servicio
systemctl --user status autocommit.service

# Ver logs en tiempo real
journalctl --user -u autocommit.service -f

# Listar timers activos
systemctl --user list-timers

# Detener timer
systemctl --user stop autocommit.timer

# Deshabilitar timer
systemctl --user disable autocommit.timer

# Ejecutar manualmente
systemctl --user start autocommit.service
```

---

## 🔧 Requisitos para Fedora 43

### Cron

```bash
# Instalar cronie si no está instalado
sudo dnf install cronie

# Habilitar servicio
sudo systemctl enable --now crond
```

### Git

Asegúrate de tener configuradas las credenciales de Git para push sin contraseña:

```bash
# Opción 1: SSH Key
ssh-keygen -t ed25519 -C "tu@email.com"
cat ~/.ssh/id_ed25519.pub
# Agregar a GitHub Settings > SSH Keys

# Opción 2: Credential Helper
git config --global credential.helper store
# (guardará credenciales después del primer push)

# Opción 3: GitHub CLI
gh auth login
```

---

## 📝 Formato de Commits

El script genera commits siguiendo **Conventional Commits** con documentación **What? For? Impact?**:

```
<type>(<scope>): <description>

What?
Automated commit with changes to bootcamp content.

For?
Track incremental progress and maintain version history.

Impact?
- Files modified: N
- Changed files:
  - file1.md
  - file2.ino
  - ...

[Automated commit by autocommit.sh]
```

### Tipos de Commit

| Tipo    | Uso                                         |
| ------- | ------------------------------------------- |
| `docs`  | Archivos `.md`                              |
| `feat`  | Código Arduino (`.ino`, `.cpp`, `.c`, `.h`) |
| `style` | Assets (`.svg`, `.png`, `.jpg`)             |
| `chore` | Scripts, configuración, gitignore           |

### Scopes

| Scope                 | Carpeta               |
| --------------------- | --------------------- |
| `week-01` a `week-10` | `bootcamp/semana-XX/` |
| `assets`              | `_assets/`            |
| `docs`                | `_docs/`              |
| `scripts`             | `_scripts/`           |
| `config`              | `.github/`            |
| `bootcamp`            | Otros archivos        |

---

## 🐛 Troubleshooting

### El script no hace push

1. Verifica credenciales de Git:

   ```bash
   git push origin main
   ```

2. Si pide contraseña, configura credenciales (ver arriba)

### No hay commits

1. Verifica que hay cambios:

   ```bash
   cd /home/epti/Documents/epti-dev/bc-channel/bc-arduino
   git status
   ```

2. Si no hay cambios, es normal que no se generen commits

### Timer no funciona

1. Verifica estado:

   ```bash
   systemctl --user status autocommit.timer
   ```

2. Verifica logs:

   ```bash
   journalctl --user -u autocommit.service --since "5 minutes ago"
   ```

3. Ejecuta manualmente para verificar:
   ```bash
   ./autocommit.sh
   ```

---

## 📄 Licencia

MIT - Bootcamp Arduino © 2025
