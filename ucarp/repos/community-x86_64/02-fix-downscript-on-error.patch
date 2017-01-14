--- ucarp-1.5.1.orig/src/carp.c
+++ ucarp-1.5.1/src/carp.c
@@ -843,6 +843,9 @@
         if ((pfds[0].revents & (POLLERR | POLLHUP)) != 0) {
             logfile(LOG_ERR, _("exiting: pfds[0].revents = %d"),
                     pfds[0].revents);
+            if ((sc.sc_state != BACKUP) && (shutdown_at_exit != 0)) {
+                (void) spawn_handler(dev_desc_fd, downscript);
+            }
             break;
         }
         if (gettimeofday(&now, NULL) != 0) {
