# YellowCol

The goal of this project is to find an equation which, from columns A B C D E F of an excel file, finds column G.

The evaluation function is the standard deviation on all points
```
    __________________________________
   /1 __ n                          2 
| / -\    {(f(a, b, c, d, e, f) - g) }
|/  n/__ 1
```

## Travis

[![Build Status](https://travis-ci.com/PamplemousseMR/YellowCol.svg?branch=master)](https://travis-ci.com/PamplemousseMR/YellowCol)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

- [easea](http://easea.unistra.fr/index.php/EASEA_platform) : An Artificial Evolution platform that allows to implement evolutionary algorithms and to exploit the massive parallelism of many-core architectures.

### Compilation

Generate the project by using easea : `./easea YellowCol.ez`.

Apply the patch : `./hack.sh`.

Compile using the makefile : `make`.

```
- clear : Clean previous compilation.
```

### Use

Start the program  : `./YellowCol`.

## Authors

* **MANCIAUX Romain** - *Initial work* - [PamplemousseMR](https://github.com/PamplemousseMR).
* **HANSER Florian** - *Initial work* - [ResnaHF](https://github.com/ResnaHF).

## License

This project is licensed under the GNU Lesser General Public License v3.0 - see the [LICENSE.md](LICENSE.md) file for details.