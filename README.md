# Antman
### Description
Antman is a compression and decompression tool for text, HTML, and P3 PPM files. It uses the LZSS algorithm to compress and decompress files. The tool can be used through the command line with the `antman` and `giantman` executables.
This project was carried out with [ZKAW](https://github.com/ZKAW) during my first year at Epitech.

* Compile the project:
```bash
make
```

### Compression
To compress a file, use the following command:
```bash
./antman/antman file file_type
```

Where `file` is the file you want to compress and `file_type` is one of the following:

* 1 for text files
* 2 for HTML files
* 3 for P3 PPM files

### Decompression
To decompress a file, use the following command:
```bash
./giantman/giantman file file_type
```

Where `file` is the file you want to decompress and `file_type` is one of the following:

* 1 for text files
* 2 for HTML files
* 3 for P3 PPM files

Use `-h` flag for more information about usage and options.
