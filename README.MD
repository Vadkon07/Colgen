<p align="center">
  <img src="https://img.shields.io/badge/LICENSE-MIT-green"/>
</p>

# ***Colgen***

Simple app to generate HEX colors (soon we will add more (RGB, RGBA))

## Requirements

OS: Linux, Windows
RAM: 128MB
GPU: any

## Installation

### Prerequisites
Make sure GTK3 is installed on your system. If not, you can install them with the following commands:
```bash
sudo apt-get install libgtk-3-dev
```

### Compilation
After installing the required libraries, compile the app using:

```bash
gcc -o colgen main.c `pkg-config --cflags --libs gtk+-3.0`
```

Running the Application
Once compiled, run the application with:
```bash
./colgen
```

## Features
- **Offline:** This app is fully offline, so you can use her even when you're not connected to internet.

<p align="center">
  <img src="https://img.shields.io/badge/LICENSE-MIT-green"/>
</p>

## To-Do
Below is a list of potential features that can be added in future versions of the app:

- [ ] **More Formats:** Add formats as RGB and RGBA.
- [ ] **Show Color's Value in GUI of app.**

## License

This project is licenced under the MIT.
