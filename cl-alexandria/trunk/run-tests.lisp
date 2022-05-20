(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(asdf:load-system "alexandria/tests")

(uiop:quit (if (alexandria/tests::run-tests) 0 1))
