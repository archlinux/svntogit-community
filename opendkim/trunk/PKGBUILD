# Maintainer: Thomas Jost <schnouki@schnouki.net>
pkgname=opendkim
pkgver=2.5.2
pkgrel=1
pkgdesc="An open source implementation of the DKIM sender authentication system. Based on a fork of dkim-milter."
arch=(i686 x86_64)
url="http://www.opendkim.org/"
license=('BSD, Sendmail')
depends=("db" "openssl")
makedepends=("libmilter")
options=(!libtool)
backup=(etc/conf.d/opendkim)
install=opendkim.install
source=(http://downloads.sourceforge.net/project/$pkgname/$pkgname-$pkgver.tar.gz
        opendkim.conf
        opendkim.rc)
md5sums=('3c2a71372ee279b627e3f39c87a0d457'
         '3e2bb1058ac0662f01e675aa6ac7ee8f'
         '093f5c098a45cc68753f97e45a5b374c')
sha256sums=('fb6994ea4bbd7e93772517cd3ee0b4ec338ed502a920fa2fa98b34869db167a9'
            'a3b5ecf4f4fe4a79392a75f7c4b6cc93a51ef8503215bb0f64d795f8754d4b68'
            '2cb7e359899dcd5c3f5e2e34f917835b77ee0ee4716d301f00996d69272f71a7')

build() {
  cd "$srcdir/$pkgname-$pkgver"

  ./configure --prefix=/usr --with-db
  make
}

check() {
  cd "$srcdir/$pkgname-$pkgver"
  make check
}

package() {
  cd "$srcdir/$pkgname-$pkgver"

  make DESTDIR="$pkgdir/" install

  # Sample configuration
  mkdir -p "$pkgdir/etc/opendkim"
  mv "$pkgdir/usr/share/doc/opendkim/opendkim.conf.sample" "$pkgdir/etc/opendkim/opendkim.conf.sample"
  chmod 0700 "$pkgdir/etc/opendkim"
  chmod 0600 "$pkgdir/etc/opendkim/opendkim.conf.sample"

  # Init script
  install -Dm644 "$srcdir/opendkim.conf" "$pkgdir/etc/conf.d/opendkim"
  install -Dm755 "$srcdir/opendkim.rc" "$pkgdir/etc/rc.d/opendkim"

  # Remove empty dirs
  rmdir "$pkgdir/usr/share/man/man1" "$pkgdir/usr/share/man/man3"

  # License
  mkdir -p "$pkgdir/usr/share/licenses/opendkim"
  for f in LICENSE LICENSE.Sendmail; do
    ln -s ../../doc/opendkim/$f "$pkgdir/usr/share/licenses/opendkim/$f"
  done
}

# vim:set ts=2 sw=2 et:
