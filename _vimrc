source $VIMRUNTIME/vimrc_example.vim

set diffexpr=MyDiff()
function MyDiff()
  let opt = '-a --binary '
  if &diffopt =~ 'icase' | let opt = opt . '-i ' | endif
  if &diffopt =~ 'iwhite' | let opt = opt . '-b ' | endif
  let arg1 = v:fname_in
  if arg1 =~ ' ' | let arg1 = '"' . arg1 . '"' | endif
  let arg1 = substitute(arg1, '!', '\!', 'g')
  let arg2 = v:fname_new
  if arg2 =~ ' ' | let arg2 = '"' . arg2 . '"' | endif
  let arg2 = substitute(arg2, '!', '\!', 'g')
  let arg3 = v:fname_out
  if arg3 =~ ' ' | let arg3 = '"' . arg3 . '"' | endif
  let arg3 = substitute(arg3, '!', '\!', 'g')
  if $VIMRUNTIME =~ ' '
    if &sh =~ '\<cmd'
      if empty(&shellxquote)
        let l:shxq_sav = ''
        set shellxquote&
      endif
      let cmd = '"' . $VIMRUNTIME . '\diff"'
    else
      let cmd = substitute($VIMRUNTIME, ' ', '" ', '') . '\diff"'
    endif
  else
    let cmd = $VIMRUNTIME . '\diff'
  endif
  let cmd = substitute(cmd, '!', '\!', 'g')
  silent execute '!' . cmd . ' ' . opt . arg1 . ' ' . arg2 . ' > ' . arg3
  if exists('l:shxq_sav')
    let &shellxquote=l:shxq_sav
  endif
endfunction


syntax enable
colorscheme Tomorrow-Night
set guifont=Bitstream\ Vera\ Sans\ Mono:h15


set nu
set history=1000
set tabstop=4
set shiftwidth=4

set smarttab

set cindent


set showcmd

set undodir=D:\\vim\\undo
set nobackup
set noswapfile

set mouse=a

set cin
set nocp

set guifont=courier_new:h14

set clipboard+=unnamed

" GUI {{{

source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim
set cursorline
set hlsearch
" }}}

if executable("vimtweak.dll") 
autocmd guienter * call libcallnr("vimtweak","SetAlpha",210) 
endif 


"Version: 1.0 by momodi@whuacm
"Modified by ghostboyzone@gmail.com

"for ACM
"windows下操作模式
"source $VIMRUNTIME/mswin.vim
"behave mswin
imap <c-d> <c-o>dd
imap <cr> <cr><left><right>
map o o<left><right>
imap <c-]> {<cr>}<c-o>O<left><right>
noremap <f6> =a{
syn on
filetype indent on
se ru nu ar sw=4 ts=4 noswf et sta nowrap ww=<,>,[,] gfn=Consolas:h12
autocmd BufEnter * lcd %:p:h
map <c-t> :tabnew<CR>
"map <f9> :call CR()<CR><CR>
"func CR()
"exec 'update'
"if filereadable(expand('%<').'.in')
"    exec '!start cmd /c g++ -g -Wall %<.cpp -o %<.exe & pause & %< < %<.in & pause'
"else
"    exec '!start cmd /c g++ -Wall %<.cpp -o %<.exe & pause & %< & pause'
"endif
"endfunc
map <F9> :call CompileGpp()<CR>    
func! CompileGpp()    
exec "up"
exec "!g++ -std=c++11 % -o %<"    
endfunc

map <F11> :call RunGpp()<CR>
func! RunGpp()
exec "up"
exec "!D:\\vim\\ACM\\oj\\r.bat %<"
endfunc

map <f2> :call SetTitle()<CR>Gkkk
func SetTitle()
let l = 0
let l = l + 1 | call setline(l, '/*')
let l = l + 1 | call setline(l, ' * Author:  heyuhhh')
let l = l + 1 | call setline(l, ' * Created Time:  '.strftime('%c'))
let l = l + 1 | call setline(l, ' */')
let l = l + 1 | call setline(l, '#include <iostream>')
let l = l + 1 | call setline(l, '#include <algorithm>')
let l = l + 1 | call setline(l, '#include <cstring>')
let l = l + 1 | call setline(l, '#include <vector>')
let l = l + 1 | call setline(l, '#include <cmath>')
let l = l + 1 | call setline(l, '#include <set>')
let l = l + 1 | call setline(l, '#include <map>')
let l = l + 1 | call setline(l, '#include <queue>')
let l = l + 1 | call setline(l, '#include <iomanip>')
let l = l + 1 | call setline(l, '#define MP make_pair')
let l = l + 1 | call setline(l, '#define fi first')
let l = l + 1 | call setline(l, '#define se second')
let l = l + 1 | call setline(l, "#define sz(x) (int)(x).size()")
let l = l + 1 | call setline(l, "#define all(x) (x).begin(), (x).end()")
let l = l + 1 | call setline(l, "#define INF 0x3f3f3f3f")
let l = l + 1 | call setline(l, "#define Local")
let l = l + 1 | call setline(l, "#ifdef Local")
let l = l + 1 | call setline(l, "  #define dbg(args...) do { cout << #args << \" -> \"; err(args); } while (0)")
let l = l + 1 | call setline(l, "  void err() { std::cout << '\\n'; }")
let l = l + 1 | call setline(l, "  template<typename T, typename...Args>")
let l = l + 1 | call setline(l, "  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }")
let l = l + 1 | call setline(l, "#else")
let l = l + 1 | call setline(l, "  #define dbg(...)")
let l = l + 1 | call setline(l, "#endif")
let l = l + 1 | call setline(l, "void pt() {std::cout << '\\n'; }")
let l = l + 1 | call setline(l, "template<typename T, typename...Args>")
let l = l + 1 | call setline(l, "void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }")
let l = l + 1 | call setline(l, 'using namespace std;')
let l = l + 1 | call setline(l, 'typedef long long ll;')
let l = l + 1 | call setline(l, "typedef pair<int, int> pii;")
let l = l + 1 | call setline(l, "\/\/head")
let l = l + 1 | call setline(l, 'const int N = 1e5 + 5;')
let l = l + 1 | call setline(l, "")
let l = l + 1 | call setline(l, "void run(){")
let l = l + 1 | call setline(l, "")
let l = l + 1 | call setline(l, "}")
let l = l + 1 | call setline(l, "")
let l = l + 1 | call setline(l, 'int main() {')
let l = l + 1 | call setline(l, "    ios::sync_with_stdio(false);")
let l = l + 1 | call setline(l, "    cin.tie(0); cout.tie(0);")
let l = l + 1 | call setline(l, "    cout << fixed << setprecision(20);")
let l = l + 1 | call setline(l, "")
let l = l + 1 | call setline(l, '    return 0;')
let l = l + 1 | call setline(l, '}')
endfunc

map<f4> :call AddComment()<cr>
func AddComment()
        if matchstr(getline('.'), '[^ ]') == '/'
        normal ^xx
    else
        normal ^i//
    endif
endfunc

set printoptions=syntax:n,number:y,portrait:y

cd D:\vim\ACM\oj

"水平滚动条
set guioptions+=b

"set encoding=utf-8
"set fileencodings=utf-8,gb2312,gb18030,gbk,ucs-bom,cp936,latin1 " ??????Ҫ?򿪵??ļ????벻?ڴ??У??Ǿ????ӽ?ȥ
"set termencoding=utf-8
"set langmenu=zh_CN.UTF-8
"language message zh_CN.UTF-8
set encoding=utf-8
set fileencodings=utf-8,chinese,latin-1
"if has("win32")
"set fileencoding=chinese
"else
set fileencoding=utf-8
"endif
"解决菜单乱码
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim
"解决consle输出乱码
"language messages zh_CN.utf-8
