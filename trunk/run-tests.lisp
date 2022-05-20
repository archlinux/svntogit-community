(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(asdf:load-system "trivial-backtrace-test")

(uiop:quit (if (asdf:test-system "trivial-backtrace") 0 1))
