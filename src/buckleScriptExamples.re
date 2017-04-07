/**
 * Examples from the BuckleScript manual: http://bloomberg.github.io/bucklescript/Manual.html
 */
print_string "!!!!!!\n";

let msg = "Hello Reason!";

print_string msg;

print_newline ();

print_string "!!!!!!\n";

external join : array string => string = "" [@@bs.module "path"] [@@bs.splice];

external readFileSync : name::string => [ | `utf8 | `my_name] [@bs.string] => string =
  "" [@@bs.module "fs"];

readFileSync name::"xx.txt" `my_name;

external test_int_type : [ | `on_closed | `on_open | `in_bin] [@bs.int] => int = "" [@@bs.val];

join [|"a", "b"|];
