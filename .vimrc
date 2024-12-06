autocmd filetype cpp nnoremap <F4> :AsyncRun -save=1 
            \ -mode=term -focus=0 -pos=right -cols=80
            \ g++ -std=c++17 -Wall -O0 -g -fsanitize=address % -o %:r  
            \ && echo Compilation complete && ./%:r < in0.txt<CR>
