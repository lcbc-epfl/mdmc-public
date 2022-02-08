# MDMDC 

Course script for the introduction to molecular dynamics and monte carlo methods for undergraduate students.

## Usage

### Building the book

If you'd like to develop on and build the mdmc book, you should:

- Clone this repository and run
- Run `pip install -r requirements.txt` (it is recommended you do this within a virtual environment)
- (Recommended) Remove the existing `mdmc/_build/` directory
- Run `jupyter-book build mdmc/`

A fully-rendered HTML version of the book will be built in `mdmc/_build/html/`.

### Hosting the book

The html version of the book is hosted on the `gh-pages` branch of this repo. A GitHub actions workflow has been created that automatically builds and pushes the book to this branch on a push or pull request to main.

If you wish to disable this automation, you may remove the GitHub actions workflow and build the book manually by:

- Navigating to your local build; and running,
- `ghp-import -n -p -f mdmc/_build/html`

This will automatically push your build to the `gh-pages` branch. More information on this hosting process can be found [here](https://jupyterbook.org/publish/gh-pages.html#manually-host-your-book-with-github-pages).



# PDF 

PDF Export works best with xelatex. Better than PDF HTML. 
Need to add labels to each formula because of the numbering 
No begin align statements
No & in the title




## Contributors

We welcome and recognize all contributions. You can see a list of current contributors in the [contributors tab](https://github.com/duerrsimon/mdmc/graphs/contributors).

## Credits

This project is created using the excellent open source [Jupyter Book project](https://jupyterbook.org/) and the [executablebooks/cookiecutter-jupyter-book template](https://github.com/executablebooks/cookiecutter-jupyter-book).

## License

Code in this repository is licensed under `MIT` License. All text is licensed under `CC by SA`.
