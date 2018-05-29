# ZSH configs
#
#export ZSH=$HOME/.oh-my-zsh
export LANG="en_US.UTF-8"

# History configs
HISTFILE=~/.zsh_history
HISTSIZE=1000
SAVEHIST=1000
# end of history

# Style configs
zstyle :compinstall filename '/home/anaboth/.zshrc'
zstyle ':completion:*:*:*:*:*' menu select
zstyle ':completion:*' matcher-list 'm:{a-zA-Z}={A-Za-z}' 'r:|=*' 'l:|=* r:|=*'
zstyle ':completion:*' list-colors ''
zstyle ':completion:*:*:kill:*:processes' list-colors '=(#b) #([0-9]#) ([0-9a-z-]#)*=01;34=0=01'
zstyle ':completion:*:*:*:*:processes' command "ps -u $USER -o pid,user,comm -w -w"
zstyle ':completion:*:cd:*' tag-order local-directories directory-stack path-directories
zstyle ':completion::complete:*' use-cache 1
zstyle ':completion::complete:*' cache-path $ZSH_CACHE_DIR
zstyle ':completion:*:*:*:users' ignored-patterns \
        adm amanda apache at avahi avahi-autoipd beaglidx bin cacti canna \
        clamav daemon dbus distcache dnsmasq dovecot fax ftp games gdm \
        gkrellmd gopher hacluster haldaemon halt hsqldb ident junkbust kdm \
        ldap lp mail mailman mailnull man messagebus  mldonkey mysql nagios \
        named netdump news nfsnobody nobody nscd ntp nut nx obsrun openvpn \
        operator pcap polkitd postfix postgres privoxy pulse pvm quagga radvd \
        rpc rpcuser rpm rtkit scard shutdown squid sshd statd svn sync tftp \
        usbmux uucp vcsa wwwrun xfs '_*'
zstyle '*' single-ignored show

autoload -U compinit vcs_info
compinit
zmodload -i zsh/complist
# end of style

WORDCHARS='' # I don't fucking know what the fuck is this

# Keybindings configs
bindkey -e
bindkey -M menuselect '^o' accept-and-infer-next-history
if (( ${+terminfo[smkx]} )) && (( ${+terminfo[rmkx]} )); then
  function zle-line-init() {
    echoti smkx
  }
  function zle-line-finish() {
    echoti rmkx
  }
  zle -N zle-line-init
  zle -N zle-line-finish
fi

bindkey '^r' history-incremental-search-backward      # [Ctrl-r] - Search backward incrementally for a specified string. The string may begin with ^ to anchor the search to the beginning of the line.
if [[ "${terminfo[kpp]}" != "" ]]; then
  bindkey "${terminfo[kpp]}" up-line-or-history       # [PageUp] - Up a line of history
fi
if [[ "${terminfo[knp]}" != "" ]]; then
  bindkey "${terminfo[knp]}" down-line-or-history     # [PageDown] - Down a line of history
fi

# start typing + [Up-Arrow] - fuzzy find history forward
if [[ "${terminfo[kcuu1]}" != "" ]]; then
  autoload -U up-line-or-beginning-search
  zle -N up-line-or-beginning-search
  bindkey "${terminfo[kcuu1]}" up-line-or-beginning-search
fi
# start typing + [Down-Arrow] - fuzzy find history backward
if [[ "${terminfo[kcud1]}" != "" ]]; then
  autoload -U down-line-or-beginning-search
  zle -N down-line-or-beginning-search
  bindkey "${terminfo[kcud1]}" down-line-or-beginning-search
fi

if [[ "${terminfo[khome]}" != "" ]]; then
  bindkey "${terminfo[khome]}" beginning-of-line      # [Home] - Go to beginning of line
fi
if [[ "${terminfo[kend]}" != "" ]]; then
  bindkey "${terminfo[kend]}"  end-of-line            # [End] - Go to end of line
fi

bindkey ' ' magic-space                               # [Space] - do history expansion

bindkey '^[[1;5C' forward-word                        # [Ctrl-RightArrow] - move forward one word
bindkey '^[[1;5D' backward-word                       # [Ctrl-LeftArrow] - move backward one word

if [[ "${terminfo[kcbt]}" != "" ]]; then
  bindkey "${terminfo[kcbt]}" reverse-menu-complete   # [Shift-Tab] - move through the completion menu backwards
fi

bindkey '^?' backward-delete-char                     # [Backspace] - delete backward
if [[ "${terminfo[kdch1]}" != "" ]]; then
  bindkey "${terminfo[kdch1]}" delete-char            # [Delete] - delete forward
else
  bindkey "^[[3~" delete-char
  bindkey "^[3;5~" delete-char
  bindkey "\e[3~" delete-char
fi

# Edit the current command line in $EDITOR
autoload -U edit-command-line
zle -N edit-command-line
bindkey '\C-x\C-e' edit-command-line
# end of keybindings


# Options settings
setopt appendhistory
setopt autocd
setopt extendedglob
setopt append_history
setopt extended_history
setopt hist_expire_dups_first
setopt hist_ignore_dups
setopt hist_ignore_space
setopt hist_verify
setopt inc_append_history
setopt share_history
setopt auto_pushd
setopt pushd_ignore_dups
setopt pushdminus
unsetopt menu_complete
unsetopt flowcontrol
setopt auto_menu
setopt complete_in_word
setopt always_to_end
# end of options

source /home/anaboth/.config/scripts/fast-syntax-highlighting/fast-syntax-highlighting.plugin.zsh

#powerline-daemon -q
#. /usr/share/zsh/site-contrib/powerline.zsh
#
zstyle ':vcs_info:*' formats %b

function git_branch() {
  vcs_info
  if [[ ! ${vcs_info_msg_0_} = $NULL ]]
  then
    echo "%F{$mainColor}-%f(%F{$mainColor}${vcs_info_msg_0_}%f)"
  fi
}
#PS1="$(git_branch)%F{green}[%(!.%F{red}.)%n%(!.%F{green}.)@%M]%f-%F{magenta}[%2~]%f%(!.-%F{red}[WHAT THE FUCK ARE YOU DOING AS ROOT?]%f.)%0(?..-%F{red}[%?]%f)
#> "
separator=$'\ue0b0'
PS1="%F{black}%K{magenta} %~ %k%f%F{magenta}$separator%f "

# Aliases
#
alias md='mkdir -p'
alias javar='java -jar'
alias ping=' ping -c 5'
alias 'cd..'='cd ..'
alias promptreload='source ~/.zshrc'
alias promptedit='vim ~/.zshrc'
alias ls='ls --color=auto'

EDITOR=vim
export EDITOR=vim
export KEYTIMEOUT=1
export PATH="$PATH:/home/anaboth/.local/bin:/sbin:/usr/sbin:/home/linuxbrew/.linuxbrew/bin"

# The next line updates PATH for the Google Cloud SDK.
if [ -f '/home/anaboth/Downloads/google-cloud-sdk/path.zsh.inc' ]; then source '/home/anaboth/Downloads/google-cloud-sdk/path.zsh.inc'; fi

# The next line enables shell command completion for gcloud.
if [ -f '/home/anaboth/Downloads/google-cloud-sdk/completion.zsh.inc' ]; then source '/home/anaboth/Downloads/google-cloud-sdk/completion.zsh.inc'; fi
