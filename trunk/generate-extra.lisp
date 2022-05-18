(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(uiop:quit (if (asdf:load-system "cl-unicode/build") 0 1))
