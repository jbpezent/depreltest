# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
import sys

sys.path.insert(0, os.path.abspath("/home/runner/work/depreltest/depreltest/python"))
sys.path.insert(0, os.path.abspath("/home/runner/work/depreltest/depreltest/src/"))


# -- Project information -----------------------------------------------------

project = "DEPRELTEST"
copyright = "2022-2023, UA ASRL"
author = "UA ASRL"

# The full version, including alpha/beta/rc tags
release = "0.0.1"
#autoclass_content = 'both'

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    # "breathe",
    # "exhale",
    #"sphinx_rtd_theme",
    "sphinx.ext.autodoc",
    "sphinx.ext.coverage",
    "sphinx.ext.napoleon",
    "sphinx.ext.autosummary",
    "sphinx.ext.autosectionlabel",
    "sphinx.ext.doctest",
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ["_templates"]

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]
primary_domain = "cpp"
highlight_language = "cpp"


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
# html_theme = "sphinx_rtd_theme"

html_theme = "furo"


#html_sidebars = { '**': ['globaltoc.html', 'relations.html', 'sourcelink.html', 'searchbox.html'] }

html_theme_options = {
    "light_css_variables": {
        "color-brand-primary": "red",
        "color-brand-content": "#CC3333"
    },
}

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

#html_context = {
#    'css_files': [
#        '_static/custom.css',  # overrides for wide tables in RTD theme
#        ],
#    }

# -- Options for PDF output --------------------------------------------------
pdf_documents = [
    ("index", u"rst2pdf", u"ASSET Documentation", u"UA ASRL"),
]

# -- Breathe Configuration ---------------------------------------------------
breathe_projects = {
    "ASSET": "./doxyoutput/xml",
}
breathe_default_project = "DEPRELTEST"

# -- Exhale Configuration ----------------------------------------------------
# exhale_args = {
#     "containmentFolder": "/home/runner/work/depreltest/depreltest/doc/cpp",
#     "rootFileName": "cpp_root.rst",
#     "rootFileTitle": "C++ Core Library",
#     "doxygenStripFromPath": "..",
#     "createTreeView": True,
#     "exhaleExecutesDoxygen": True,
#     "exhaleDoxygenStdin": "INPUT = /home/runner/work/depreltest/depreltest/src",
# }

# -- Autosummary -------------------------------------------------------------
autosummary_generate = True
