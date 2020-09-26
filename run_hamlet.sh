mkdir -p example
wget -qO- https://gist.githubusercontent.com/provpup/2fc41686eab7400b796b/raw/b575bd01a58494dfddc1d6429ef0167e709abf9b/hamlet.txt | build/apps/main example/hamlet.txt example/hamlet_sort.txt example/hamlet_reversed_sort.txt
