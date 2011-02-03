setenv PATH ${PATH}:/opt/java/jre/bin
if (! "$?JAVA_HOME" ) then
  setenv JAVA_HOME /opt/java/jre
endif
