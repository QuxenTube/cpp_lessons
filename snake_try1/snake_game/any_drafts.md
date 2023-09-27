## Some drafts

### backspace
```c++
cout << "\033[1G" << "\033[100X";
```

### Dynamic array with void()
```c++
void settings(size_t size_w, size_t size_h) {
	int** rows = new int*[size_h];
	// int* cols = new int[size_w];
	for (int i = 0; i < size_h; i++) {
		rows[i] = new int[size_w];
	}
	rows[size_h][size_w] = 500;
	cout << rows[size_h][size_w] << endl;


	// return rows;
}
```

