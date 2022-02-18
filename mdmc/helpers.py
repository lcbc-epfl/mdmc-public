# Style helper to insert styling into the notebooks

from IPython.core.display import HTML

def set_style():
    return HTML('''<style>
    .admonition, div.admonition{margin: 0em auto;
    padding: 0 .6rem .8rem;
    overflow: hidden;
    page-break-inside: avoid;
    border-left: .2rem solid;
    border-left-color: rgba(var(--pst-color-admonition-default),1);
    border-bottom-color: rgba(var(--pst-color-admonition-default),1);
    border-right-color: rgba(var(--pst-color-admonition-default),1);
    border-top-color: rgba(var(--pst-color-admonition-default),1);
    border-radius: .2rem;
    box-shadow: 0 .2rem .5rem rgba(0,0,0,.05),0 0 .0625rem rgba(0,0,0,.1);
    transition: color .25s,background-color .25s,border-color .25s;}
.exercise {
    border-color: #b51f1f !important;
}
     div.admonition, div.topic, blockquote {
    clear: left;
}

div.admonition {
    margin-top: 10px;
    margin-bottom: 10px;
}

.admonition {
    border-radius: .4em;
    box-shadow: 0 0.2rem 0.5rem rgb(0 0 0 / 5%), 0 0 0.0625rem rgb(0 0 0 / 10%);
}

.admonition>.title, div.admonition>.title {
    position: relative;
  margin-top:-10px;
  margin-left:-0.7em;
    padding: .4rem .6rem .4rem .6rem;
    font-weight: 700;
    }

.exercise>.title {
    background-color: #e6e6e6 !important;
    color: #212121 !important;
}
     </style>''')
