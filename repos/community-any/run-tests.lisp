(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(asdf:load-system "trivial-garbage/tests")

(uiop:quit (if (trivial-garbage-tests:run) 0 1))
