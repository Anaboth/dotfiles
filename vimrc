python3 from powerline.vim import setup as powerline_setup
python3 powerline_setup()
python3 del powerline_setup

set path+=**
set laststatus=2
set showtabline=2
set tabstop=4
set t_Co=256
set noshowmode
set cindent
set number
set relativenumber
set wildmenu
set nocompatible

syntax on
filetype plugin on
command! MakeTags !ctags -R .

let g:netrw_banner=0        " disable annoying banner
let g:netrw_browse_split=4  " open in prior window
let g:netrw_altv=1          " open splits to the right
let g:netrw_liststyle=3     " tree view
let g:netrw_list_hide=netrw_gitignore#Hide()
let g:netrw_list_hide.=',\(^\|\s\s\)\zs\.\S\+'

if empty(glob('~/.vim/autoload/plug.vim'))
  silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
    \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif

augroup numbertoggle
  autocmd!
  autocmd BufEnter,FocusGained,InsertLeave * set relativenumber
  autocmd BufLeave,FocusLost,InsertEnter   * set norelativenumber
augroup END

noh

inoremap {      {}<Left>
inoremap {<CR>  {<CR><CR>}<Up><Tab>
inoremap {{     {
inoremap {}     {}

inoremap        <  <><Left>

inoremap        (  ()<Left>
inoremap <expr> )  strpart(getline('.'), col('.')-1, 1) == ")" ? "\<Right>" : ")"

inoremap <expr> ' strpart(getline('.'), col('.')-1, 1) == "\'" ? "\<Right>" : "\'\'\<Left>"
inoremap <expr> " strpart(getline('.'), col('.')-1, 1) == "\"" ? "\<Right>" : "\"\"\<Left>"

call plug#begin('~/.vim/plugged')
call plug#end()
