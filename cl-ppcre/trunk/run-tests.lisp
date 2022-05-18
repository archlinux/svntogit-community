(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(asdf:load-system "cl-ppcre-unicode/test")

(uiop:quit (if (cl-ppcre-test:run-all-tests :more-tests 'cl-ppcre-test:unicode-test) 0 1))
