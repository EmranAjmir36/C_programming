# Shared helpers for ./gcc and ./run

COMPOSE_FILE=".docker/compose.yaml"

if [ -t 1 ]; then
  BOLD=$'\e[1m'; DIM=$'\e[2m'; RESET=$'\e[0m'
  RED=$'\e[31m'; GREEN=$'\e[32m'; YELLOW=$'\e[33m'; BLUE=$'\e[34m'; MAGENTA=$'\e[35m'; CYAN=$'\e[36m'
else
  BOLD=; DIM=; RESET=; RED=; GREEN=; YELLOW=; BLUE=; MAGENTA=; CYAN=
fi

info()  { printf '%s\n' "  ${BLUE}${BOLD}●${RESET} $*"; }
ok()    { printf '%s\n' "  ${GREEN}${BOLD}✔${RESET} $*"; }
fail()  { printf '%s\n' "  ${RED}${BOLD}✘${RESET} $*" >&2; }
hint()  { printf '%s\n' "    ${DIM}$*${RESET}" >&2; }

rule() {
  local cols label="$1" line
  cols=$(tput cols 2>/dev/null || echo 60)
  [ "$cols" -gt 60 ] && cols=60
  line=$(printf '%*s' "$((cols - ${#label} - 6))" '' | tr ' ' '─')
  if [ -n "$label" ]; then
    printf '%s\n' "  ${DIM}──${RESET} ${MAGENTA}${label}${RESET} ${DIM}${line}${RESET}"
  else
    printf '%s\n' "  ${DIM}$(printf '%*s' "$((cols - 2))" '' | tr ' ' '─')${RESET}"
  fi
}

now() { perl -MTime::HiRes=time -e 'printf "%.3f", time' 2>/dev/null || date +%s; }
elapsed() { perl -e 'printf "%.2fs", $ARGV[1] - $ARGV[0]' "$1" "$(now)" 2>/dev/null || echo "?"; }

# Build the image on first use, quietly.
ensure_image() {
  if ! docker info >/dev/null 2>&1; then
    fail "Docker isn't running."
    hint "Start Docker Desktop and try again."
    exit 1
  fi
  if ! docker image inspect c_programming:latest >/dev/null 2>&1; then
    info "Setting up the C environment ${DIM}(first time only)…${RESET}"
    if ! docker compose -f "$COMPOSE_FILE" build -q >/dev/null 2>&1; then
      fail "Couldn't build the Docker image."
      hint "Try: docker compose -f $COMPOSE_FILE build"
      exit 1
    fi
    ok "Environment ready"
  fi
}

# Run a command in the container without Compose's status chatter.
in_container() {
  local tty_flag=""
  { [ -t 0 ] && [ -t 1 ]; } || tty_flag="-T"
  docker compose --progress quiet -f "$COMPOSE_FILE" run --rm $tty_flag c "$@"
}
