# $Id$
# Maintainer: Sébastien Luttringer

pkgname=aiccu
pkgver=20070115
pkgrel=1
pkgdesc='SixXS Automatic IPv6 Connectivity Client Utility'
arch=('i686' 'x86_64')
url='http://www.sixxs.net/tools/aiccu/'
license=('custom')
depends=('gnutls' 'iproute2')
backup=('etc/aiccu.conf')
source=("http://www.sixxs.net/archive/sixxs/aiccu/unix/${pkgname}_${pkgver}.tar.gz"
        'aiccu.service')
md5sums=('c9bcc83644ed788e22a7c3f3d4021350'
         '4c7c350df0fab707c1524389519f0f04')

build() {
  cd $pkgname
  [[ $LDFLAGS ]] && LDFLAGS="$LDFLAGS,--no-as-needed"
  make
}

package() {
  cd $pkgname
  make DESTDIR="$pkgdir" install
  # default config
  install -Dm640 doc/aiccu.conf "$pkgdir/etc/aiccu.conf"
  # license
  install -Dm644 doc/LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  # doc
  install -dm755 "$pkgdir/usr/share/doc/$pkgname"
  install -m644 doc/{README,HOWTO,changelog} "$pkgdir/usr/share/doc/$pkgname/"
  install -Dm644 doc/$pkgname.1 "$pkgdir/usr/share/man/man1/$pkgname.1"
  # systemd
  install -Dm644 "$srcdir/aiccu.service" "$pkgdir/usr/lib/systemd/system/aiccu.service"
  rm -r "$pkgdir/etc/init.d"
}

# vim:set ts=2 sw=2 et:
