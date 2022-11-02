set encoding=utf-8
set nocompatible
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'thinca/vim-ref'
Plugin 'VundleVim/Vundle.vim'
Plugin 'majutsushi/tagbar'
Plugin 'rafi/awesome-vim-colorschemes'
Plugin 'junegunn/fzf.vim'
Plugin 'tpope/vim-fugitive'
Plugin 'scrooloose/syntastic'
Plugin 'vim-airline/vim-airline'
Plugin 'arcticicestudio/nord-vim'
Plugin 'jiangmiao/auto-pairs'
Plugin 'ycm-core/YouCompleteMe'
Plugin 'ervandew/supertab'
Plugin 'preservim/nerdcommenter'
Plugin 'preservim/nerdtree'
Plugin 'lervag/vimtex'
Plugin 'ryanoasis/vim-devicons'
Plugin 'morhetz/gruvbox'
Plugin 'vim-utils/vim-man'
Plugin 'ctrlpvim/ctrlp.vim'
call vundle#end()
autocmd vimenter * ++nested colorscheme gruvbox
filetype plugin indent on
filetype plugin on
set number
set relativenumber
set smarttab
map <F8> :w <CR> :!gcc % -lm -o %< && ./%< <CR>
map <F7> :!./%< <CR>
nmap <F6> :TagbarToggle<CR>
set tabstop=2
set shiftwidth=2
set autoindent
set mouse=a
set ruler
syntax enable
set background=dark
colorscheme gruvbox
autocmd BufNewFile *.c 0r ~/.vim/templates/cbasic.c
autocmd BufWinEnter *.c call cursor(5,0)
let g:ycm_semantic_triggers = {
			\ 'c,cpp,objc': [ 're!\w{1}', '_' ], 
			\ }
nnoremap <C-n> :NERDTree<CR>

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0

let g:AutoPairsFlyMode = 1
