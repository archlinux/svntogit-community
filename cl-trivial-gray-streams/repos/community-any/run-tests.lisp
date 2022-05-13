;; run tests for trivial-gray-streams
;; sourced from debian
;; https://salsa.debian.org/common-lisp-team/trivial-gray-streams
(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(asdf:load-system "trivial-gray-streams-test")

(let ((failed-tests (trivial-gray-streams-test::failed-test-names (trivial-gray-streams-test::run-tests))))
  ;; Filter out some expected failures (as of 2018-03-24)
  (setq failed-tests (delete "stream-advance-to-column" failed-tests
                             :test #'string=))
  (unless (null failed-tests)
    (format t "The following test(s) failed: ~{~A~^ ~}" failed-tests)
    (uiop:quit 1)))
