(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(asdf:load-system "bordeaux-threads/test")
(asdf:load-system "fiveam")

(uiop:quit (if (fiveam:run :bordeaux-threads) 0 1))
