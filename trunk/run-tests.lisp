(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(asdf:load-system "global-vars-test")

(uiop:quit (if (asdf:test-system "global-vars-test") 0 1))
