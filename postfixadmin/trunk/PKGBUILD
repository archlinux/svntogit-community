# Contributor: Filip <fila pruda.com>

pkgname=postfixadmin
pkgver=2.3.6
pkgrel=2
pkgdesc="web based interface used to manage mailboxes, virtual domains and aliases created for Postfix"
arch=('any')
license=('GPL')
url="http://postfixadmin.sourceforge.net/"
backup=(etc/webapps/postfixadmin/config.inc.php etc/webapps/postfixadmin/.htaccess
	etc/webapps/postfixadmin/motd.txt etc/webapps/postfixadmin/motd-users.txt)
depends=('php')
optdepends=(	'mariadb: MySQL server'
		'postgresql: PostgreSQL server'
	   )

source=(http://downloads.sourceforge.net/project/postfixadmin/postfixadmin/postfixadmin-$pkgver/postfixadmin-$pkgver.tar.gz)

md5sums=('2976aa2126747a25fa006b7be67ba9ba')

package() {

  _destdir=$pkgdir/usr/share/webapps/postfixAdmin
  _destdir_etc=$pkgdir/etc/webapps/postfixadmin
  _destdir_doc=$pkgdir/usr/share/doc/postfixadmin
  
  install -dm755 ${_destdir}
  install -dm755 ${_destdir_etc}
  install -dm755 ${_destdir_doc}
  
  cd $srcdir/$pkgname-$pkgver
  cp -r * ${_destdir}
  
  #etc
  mv ${_destdir}/config.inc.php ${_destdir_etc}
  ln -s /etc/webapps/postfixadmin/config.inc.php ${_destdir}/config.inc.php
  echo "#deny from all" >${_destdir_etc}/.htaccess || return 1
  ln -s /etc/webapps/postfixadmin/.htaccess ${_destdir}/.htaccess
  mv ${_destdir}/motd.txt ${_destdir_etc}
  mv ${_destdir}/motd-users.txt ${_destdir_etc}
  ln -s /etc/webapps/postfixadmin/motd.txt ${_destdir}/motd.txt
  ln -s /etc/webapps/postfixadmin/motd-users.txt ${_destdir}/motd-users.txt
  
  #move documents
  mv ${_destdir}/*.TXT ${_destdir_doc}
  mv ${_destdir}/tests ${_destdir_doc}
  mv ${_destdir}/ADDITIONS ${_destdir_doc}
  mv ${_destdir}/DOCUMENTS ${_destdir_doc}
  mv ${_destdir}/VIRTUAL_VACATION ${_destdir_doc}
  rm -rf ${_destdir}/debian
  
  # apache  
  cat >${_destdir_etc}/apache.example.conf <<EOF
        Alias /postfixAdmin "/usr/share/webapps/postfixAdmin"
        <Directory "/usr/share/webapps/postfixAdmin">
                AllowOverride All
                Options FollowSymlinks
                Order allow,deny
                Allow from all
		php_admin_value open_basedir "/tmp/:/usr/share/webapps/postfixAdmin/:/etc/webapps/postfixadmin/:/usr/share/pear/"
        </Directory>
EOF
  
}
