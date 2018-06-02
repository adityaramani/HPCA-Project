cd /home/aditya/Desktop/HPCA/word_count_openmp

gcc word_count.c -fopenmp

./a.out 1.in 1  >> ./output/wc_1t_11.txt;  
./a.out 2.in 1  >> ./output/wc_1t_14.txt;  
./a.out 3.in 1  >> ./output/wc_1t_17.txt;  
./a.out 4.in 1  >> ./output/wc_1t_20.txt;  
./a.out 5.in 1  >> ./output/wc_1t_23.txt;  

 ./a.out 1.in 4  >> ./output/wc_4t_11.txt; 
 ./a.out 2.in 4  >> ./output/wc_4t_14.txt; 
 ./a.out 3.in 4  >> ./output/wc_4t_17.txt; 
 ./a.out 4.in 4  >> ./output/wc_4t_20.txt; 
 ./a.out 5.in 4  >> ./output/wc_4t_23.txt; 

./a.out 1.in 8  >> ./output/wc_8t_11.txt; 
./a.out 2.in 8  >> ./output/wc_8t_14.txt; 
./a.out 3.in 8  >> ./output/wc_8t_17.txt; 
./a.out 4.in 8  >> ./output/wc_8t_20.txt; 
./a.out 5.in 8  >> ./output/wc_8t_23.txt; 

./a.out 1.in 16  >> ./output/wc_16t_11.txt; 
./a.out 2.in 16  >> ./output/wc_16t_14.txt; 
./a.out 3.in 16  >> ./output/wc_16t_17.txt; 
./a.out 4.in 16  >> ./output/wc_16t_20.txt; 
./a.out 5.in 16  >> ./output/wc_16t_23.txt; 
