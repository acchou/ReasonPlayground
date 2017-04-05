# ReasonPlayground

A playground for the [`Reason`](http://facebook.github.io/reason/) language
based on [`ReasonProject`](https://github.com/reasonml/ReasonProject).

Features: all of the features of ReasonProject, plus:

- [`BuckleScript`](bucklescript) integration

## Install

```sh
git clone https://github.com/acchou/ReasonPlayground.git
cd ReasonPlayground
npm install
```

## Run, Change, Rebuild

```sh
npm run reasonBuild  # Rebuilds after changing
npm run start        # Runs the compiled app
npm run clean        # Clean if you need to!
npm run top          # REPL (rtop)
npm run buckleWatch  # Compile to JavaScript using BuckleScript (in watch mode)
```

The `reasonBuild` target produces a native executable file `Test.native` in
the project directory and other build artifacts in `_build`. The `start`
target runs the native app.

The `buckleWatch` target produces JavaScript output in `lib/js`.

## Source Code

Source code is in `src/`.

## Editor Support

All of the IDE plugins, including integration with error highlighting,
autocomplete, and syntax highlighting are included inside of the built project.

I prefer emacs. To install emacs integration, first install global Reason CLI
tools:

```sh
npm -g install git://github.com/reasonml/reason-cli.git
```

Then add the snippet described in the
[Reason emacs support](https://github.com/facebook/reason/tree/master/editorSupport/emacs)
to your `.emacs`. I've also found that autocomplete isn't turned on by default
when opening `.re` files, but that's easy to fix by adding
`auto-complete-mode` to the Reason mode hook, like so:

```elisp
(add-hook 'reason-mode-hook (lambda ()
                              (add-hook 'before-save-hook 'refmt-before-save)
                              (auto-complete-mode)
                              (merlin-mode)))
```

Reason also supports
[Atom](http://facebook.github.io/reason/tools.html#merlin-atom) and
[Vim](https://github.com/facebook/reason/tree/master/editorSupport/VimReason).

## Developing

### Add Another Dependency

Dependencies are installed via NPM, from the `opam-alpha` repository. These
are OPAM projects that have been automatically ported to Reason. Install a
dependency into the project sandbox, and use `--save` so that your
`package.json` is updated.

```sh
npm install --save @opam-alpha/cstruct
```

This merely adds and builds the dependency. It doesn't mean your build system
will know to link to it. Accomplishing that is build system dependent, but if
using the example build system (`rebuild`, which is based on `ocamlbuild`), you
can get an idea for the options by doing `npm run buildHelp`. Typically you
need to configure the `reasonBuild` entry in `package.json` to add the `-pkg
dependencyPackage`. Consult your dependency's docs.

## Troubleshooting

In general, if something goes wrong, try deleting the local `node_modules`
directory that was installed, and then try reinstalling using `npm install -f`
(to avoid using a stale cache). Then if that doesn't work, follow the following
steps to debug your specific failed dependency.

Also, remember to disable any system ocaml compilers that you have in your PATH.
For example, if you installed an OCaml compiler via opam, comment out the line in
your `~/.bashrc` or `~/.bash_profile` that source the opam environment,
and then open a new shell.

> Note: We will soon make it impossible for these kinds of conflicts to occur.

Also see [`ReasonProject`](https://github.com/reasonml/ReasonProject) for more
troubleshooting ideas.
