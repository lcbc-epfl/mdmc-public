# Style helper to insert styling into the notebooks

from IPython.core.display import HTML
import MDAnalysis
import py3Dmol as p3d
import ipywidgets
import ast

import tempfile

def mduniverse_to_pdb(u, ts):
    tf = tempfile.NamedTemporaryFile()  
    u.trajectory[ts]
    with MDAnalysis.Writer(tf.name, format="pdb") as W:
        W.write(u)
    return tf.read().decode("utf-8") 

def get_pdb_max_index(file_name):
    pdb_file = open(file_name, "r")
    current_index = 0
    data = ""
    for line in pdb_file:
        if 'ENDMDL' in line:
            current_index += 1
    pdb_file.close()
    return current_index

def get_n_frames(structure):
    if type(structure) == str:
        n_frames = get_pdb_max_index(structure)
    else:
        n_frames=len(structure.trajectory)
    return n_frames

def read_pdb_index(file_name, index=0):
    """Reads one configuration defined by its index from a PDB file."""
    pdb_file = open(file_name, "r")
    current_index = 0
    data = ""
    for line in pdb_file:
        if index == current_index:
            data += line
        if 'ENDMDL' in line:
            if index == current_index:
                break
            current_index += 1
    pdb_file.close()
    if current_index!=index:
        data = read_pdb_index(file_name, index=0)
    return data

def parse_structure(struc, ts):
    if type(struc)==str:
        return read_pdb_index(struc, index=ts)
    else:
        return mduniverse_to_pdb(struc, ts)

import warnings
    
def return_viewer(structure=None, step=0, cartoon="Hide", sidechains="Show", only_spheres=False, waters="show", customsel=None, customstyle=None):
    colorschemes=["GreenCarbon", "CyanCarbon", "BlueCarbon", "WhiteCarbon"]
    structures_to_show = []
    try:
        if type(structure)==list:
            for item in structure:
                structures_to_show.append(parse_structure(item, step))
        else: 
            structures_to_show.append(parse_structure(structure, step))
    except Exception as e:
        print(e)
        print("must be either pdb file or MDAnalysis.Universe or list of either")
    viewer = p3d.view(width=600, height=300)
    for i,struc in enumerate(structures_to_show):
        viewer.addModel(struc)
        style_dict = {}
        if not only_spheres:
            if cartoon=="Show":
                style_dict['cartoon']={"colorscheme":colorschemes[i]}
            if sidechains=="Show":
                style_dict["stick"]={"colorscheme": colorschemes[i], "radius": 0.3}
        else:
            style_dict["sphere"] = {"radius":0.3}
            
        viewer.getModel(i).setStyle(style_dict)
    if customsel!=None:
        customsel = ast.literal_eval(customsel)
    else:
        customsel = {}
    if customstyle!=None:
        customstyle = ast.literal_eval(customstyle)
        viewer.addStyle(customsel, customstyle)
    viewer.zoomTo()
    viewer.show()

def show_trajectory(structures, only_spheres=False):
    with warnings.catch_warnings():
        warnings.simplefilter("ignore")
        tab_nest = ipywidgets.Tab()
        n_frames = 0
        if type(structures) == list:
            for structure in structures:
                n_frames_temp = get_n_frames(structure)
                if n_frames_temp> n_frames:
                    n_frames = n_frames_temp
        else:
            n_frames = get_n_frames(structures)
            structures = [structures]

        play = ipywidgets.Play(
            value=0,
            min=0,
            max=n_frames-1,
            step=1,
            description="Press play",
            disabled=False,
            show_repeat=False
        )
        slider = ipywidgets.IntSlider(min=0,
            max=n_frames-1)
        ipywidgets.jslink((play, 'value'), (slider, 'value'))
        ui = ipywidgets.HBox([play, slider])

        items = [] 

        sidechain_label = ipywidgets.Label(value="Sidechains? ", style=dict(
            font_weight='bold',
        ))
        sidechains = ipywidgets.ToggleButtons(
            options=['Show', 'Hide' ],
            disabled=False,
            button_style='', # 'success', 'info', 'warning', 'danger' or ''
            icons=['eye', 'disabled']
        )
        items+= [sidechain_label, sidechains]

        cartoon_label = ipywidgets.Label(value="Cartoon?   ", style=dict(
            font_weight='bold',
        ))
        cartoon = ipywidgets.ToggleButtons(
            options=['Show', 'Hide' ],
            disabled=False,
            button_style='', # 'success', 'info', 'warning', 'danger' or ''
            icons=['eye', 'disabled']
        )
        items+=  [cartoon_label, cartoon]



        settings_box = ipywidgets.GridBox(items, layout=ipywidgets.Layout(grid_template_columns="70px auto 100px auto"))
        out = ipywidgets.interactive_output(return_viewer, {'step': slider, 'structure': ipywidgets.fixed(structures), 'cartoon':cartoon, 'sidechains':sidechains, "only_spheres":ipywidgets.fixed(only_spheres)})

        viewer_box = ipywidgets.VBox([ui, out])


        tab_nest.children = [viewer_box, settings_box]
        tab_nest.set_title(0, 'Viewer')
        tab_nest.set_title(1, 'Settings')
    return tab_nest


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
