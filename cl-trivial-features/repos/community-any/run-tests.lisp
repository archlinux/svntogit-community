(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(asdf:load-system "trivial-features-tests")

(uiop:quit (if (trivial-features-tests:run) 0 1))
