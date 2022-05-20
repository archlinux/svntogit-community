(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(asdf:load-system "fiveam/test")

(uiop:quit (if (asdf:test-system "fiveam") 0 1))
