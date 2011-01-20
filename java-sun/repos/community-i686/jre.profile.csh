setenv PATH ${PATH}:/opt/java/jre/bin
if (! -e /etc/profile.d/jdk.sh ) then
  setenv JAVA_HOME /opt/java/jre
endif
