# Tetris (MLV)

This is my first C project, made back when I was at university. It's not the most optimized nor the best Tetris out there, but it is what it is, and we were required to use [MLV](http://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/index.html) for the graphics.

Most of the code was written by me. My classmate's contributions are visible in the commit history.

## Features

- **Three game modes**: normal, survival, and a memory-based marathon mode
- **Unlimited saves**: save a game, load it back, delete it. Saves are listed in a scrollable grid (3 columns)
- **Pause** the game at any time
- **Leaderboard**
- **Custom tetriminos**: add your own pieces in the `tetriminos` folder
- **Settings page** (not fully complete, but enough to be useful):
  - key bindings
  - colorblind options (protanopia and deuteranopia)
  - some graphic options
- **Custom UI engine written from scratch in C**: components (buttons, texts, images, frames), stylesheets, hover states, transitions and a scrollbar

## Built with

- C
- [MLV](http://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/index.html), a graphics library built on top of SDL

## Credits and notes

- The "T" in the Tetris logo is the [top.gg](https://top.gg) logo. I used it back then because it looked nice for the T of Tetris. It belongs to top.gg, it's not mine and I don't claim any right over it. Please don't sue me. If top.gg (or anyone) wants it removed, just ask and I'll take it out.

I used Valgrind to track down memory errors.
