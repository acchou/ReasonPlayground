/**
 * Examples from the BuckleScript manual: http://bloomberg.github.io/bucklescript/Manual.html
 */
print_string "!!!!!!\n";

let msg = "Hello Reason!";

print_string msg;

print_newline ();

print_string "!!!!!!\n";

external join : array string => string = "" [@@bs.module "path"] [@@bs.splice];

/* bs.send helps the user send a message to a JS object. */
type id;

/* Binding to a global value */
type dom; /* Abstract type for the DOM */

external dom : dom = "document" [@@bs.val];

/* bs.send helps the user send a message to a JS object.  */
external get_by_id : dom => string => id =
  "getElementById" [@@ocaml.doc " Abstract\ntype for id object "] [@@bs.send];

/* bs.send.pipe is similar to bs.send except that the first argument, i.e, the
   object, is put in the position of last argument to help user write in a
   chaining style: */
external map : ('a => 'b) [@bs] => array 'b = "" [@@bs.send.pipe : array 'a];

external forEach : ('a => unit) [@bs] => array 'a = "" [@@bs.send.pipe : array 'a];

let test arr => arr |> map ((fun x => x + 1) [@bs]) |> forEach ((fun x => Js.log x) [@bs]);

/* There are several patterns heavily used in existing JavaScript codebases,
   for example, the string type is used a lot. BuckleScript FFI allows the user
   to model string type in a safe way by using annotated polymorphic variant. */
external readFileSync : name::string => [ | `utf8 | `my_name] [@bs.string] => string =
  "" [@@bs.module "fs"];

readFileSync name::"xx.txt" `my_name;

/* Polymoprhic variants can also be used to model enums. */
external test_int_type : [ | `on_closed | `on_open | `in_bin] [@bs.int] => int = "" [@@bs.val];

/* Using polymorphic variant to model event listener */
type readline;

external on : [ | `close (unit => unit) | `line (string => unit)] [@bs.string] => readline =
  "" [@@bs.send.pipe : readline];

let register rl => rl |> on (`close (fun _ => ())) |> on (`line (fun line => print_endline line));

join [|"a", "b"|];
