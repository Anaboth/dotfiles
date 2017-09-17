local ret_status=" %{$fg_bold[green]%}-"
PROMPT='${ret_status}%{$reset_color%} '
RPROMPT='$(git_prompt_info)%{$fg_bold[cyan]%}%c %{$fg_bold[white]%}%*%{$reset_color%}'

ZSH_THEME_GIT_PROMPT_PREFIX="%{$fg_bold[green]%}git:(%{$fg[red]%}"
ZSH_THEME_GIT_PROMPT_SUFFIX="%{$reset_color%} "
ZSH_THEME_GIT_PROMPT_DIRTY="%{$fg[green]%}) %{$fg[yellow]%}✗"
ZSH_THEME_GIT_PROMPT_CLEAN="%{$fg[green]%})"
