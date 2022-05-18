(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(asdf:load-system "cl-unicode/test")

(uiop:quit (if (cl-unicode-test:run-all-tests) 0 1))
