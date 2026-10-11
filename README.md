# Petitecc
A Go port of chibicc C compiler (all 316 commits)

This is a humble attempt to port Rui's chibicc compiler to Golang.
While Chibicc IMO is *NOT* a toy compiler, petitecc sure is.  
This is *not* AI generated. That said, of course I used AI help whenever I got stuck.

To Compile: make\
To run compiler test suite: make test\
Compiler flags help: ./petitecc --help (or just ./petitecc)\

I did this for 2 reasons:\
-Wanted to learn Go (did learn some).\
-Wanted to see how a *real* compiler works (Ok, did see, but did not always understand haha. 
Also, sometimes C is just *messy* and unnecessarily complex).

I tried to (mostly) stay close to what chibicc did, so this is not at all idiomatic Go (for example, parsing routines 
have this idiom often: (rest **Token, tok *Token) and I kept it. 

I used Go's flag package for command-line parameter handling, so petitecc is not 100% compatible 
(e.g. to link with math library, you use -lm in gcc / clang /chibicc, but -l=m in petitecc).  \
Due to that incompatibility,I didn't bother trying to compile git, cpython etc that chibicc did in the final stages of compiler.

I did however go through all 316 commits. Here is a list of commits that have something done differently from chibicc, 
also commenting some bigger refactors etc done along the way:

-Commit 150. Did not add stage2 (did not want to copy C versions' files for that).

-Commit 154. Did not do that (unnecessary).

-Commit 173. Fixed print_tokens() to (almost) work like C version (this one expands newlines, sorry)

-Commit 207. I had to completely redo my number conversion logic to more closely mimic what C version was doing. Lots of work and debugging :).

-Commit 213. Fixed crash in parse/struct_members() if mem.ty.name was nil

-Commit 215. Did not do this, because Go lacks C's opem_memstream *File API (and was lazy, hah).

-Commit 217. C compiler flags are N/A for Go.

-Commit 225. Another biggish refactor to better mimic chibicc...will I ever learn ? :) 

-Commit 226. my read_char_literal() looks *soo* ugly, I'm ashamed...but test pass :)

-Commit 228. Finally refactored read_char_literal() & read_string_literal(), much nicer hopefully now.

-Commit 237. This was a lot harder than expected, quite a wrestle (among other things, the old friend read_string_literal() :) )
            I'm not sure that C (especially signed char) and Unicode are that compatible :) ...
            Fixed a long forgotten bug in codegen/emit_data (alignment)

-Commit 262. N/A, so did nothing here (except this comment).

-Commit 269. The long overdue compiler flags refactoring finally done.

-Commit 276. Switched to use command-line convention -flag=value (e.g. -l=m, not -l m) in driver.sh and usage info 
 (convention -flag value of cource still works but is not shown in usage help)

-Commit 279. Fixed a small error in my assembly generation: .file- directive was generated twice.

-Commit 280. Didn't do long double (f80) at all, because Go (as well as many other languages / environments, 
like Microsoft Visual C, Rust, Java, Webassembly etc) lacks support for that, so in this implementation long double is just double. 
Some tests that in chibicc want sizeof(long double) to be 16, accept 8 here.
Also, in function.c I use "%lf" (not "%Lf") in sprintf() call

-Commit 285. Did not do that (string hashmap), Go already has a good one.

-Commits 294 & 295. There were no test case, so my implementation probably doesn't work.

-Commit 306. Did not even try, due to my toy compiler's incompatible command-line handling. 
            Tried chibicc to sqlite which worked well after changing repo path git to use https.

-Commit 311. Did not even try, due to my toy compiler's incompatible command-line handling. 


