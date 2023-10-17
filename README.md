# Thesaurasaurus
slow? yes. garbage? yes. works? usually. fun to write? kinda.
i named it Thesaurasaurus because it downloads a 600kb file each time and then deletes it making it big and slow and stupid.

dependencies:
either gcc or clangd

using gcc:
compile with ''' gcc thesaurus.c -o thesaurus '''
cp thesaurus /usr/bin

using clang:
i don't actually know how to do it with clang but you almost certainly can

I wrote this program in like 2.5 hours and it is a rather garbage terminal thesaurus utility. 
make sure you have an internet connection because it pulls from mariam webster because i was not about to make a whole data thing at 2am
at least 600kb of storage available because if you take a not so hard look at the code i used curl to download the plain text of the 
merriam-webster site go to line 17 of like 3500 and use only that them immediately delete the file. 
