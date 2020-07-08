# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Ian Taylor <ian at lorf dot orgs>

pkgname=autossh
pkgver=1.4g
pkgrel=2
pkgdesc="Automatically restart SSH sessions and tunnels"
arch=('x86_64')
url="https://www.harding.motd.ca/autossh/"
license=('custom')
depends=('libnsl' 'openssh')
source=("https://www.harding.motd.ca/autossh/$pkgname-$pkgver.tgz"
	"LICENSE")
sha512sums=('499b560d978736f4e764d5d828282fdaba1cbf94811ae6be0be5434d9c1cdc6ca5513d728b6372aa243843cb1b91e61cfc5fdeb77ddb0b6a7ce027218ba67466'
            'cdbdf804eb6e6480cc2be8a9b170f77f6c58e4ae2a741871cd29308ff10a1d391759bed2576b5f072aa878f9c4ae5ef7e6f9c8f38560b3ebbe4591a7220582f7')

build() {
  cd "$srcdir"/$pkgname-$pkgver
  ./configure --prefix="$pkgdir"/usr --sysconfdir=/etc --localstatedir=/var
  make
}

package() {
  cd "$srcdir"/$pkgname-$pkgver
  install -D -m755 autossh "$pkgdir"/usr/bin/autossh
  install -D -m644 CHANGES "$pkgdir"/usr/share/doc/autossh/CHANGES
  install -D -m644 README "$pkgdir"/usr/share/doc/autossh/README
  install -D -m644 autossh.host "$pkgdir"/usr/share/autossh/examples/autossh.host
  install -D -m644 rscreen "$pkgdir"/usr/share/autossh/examples/rscreen
  install -D -m644 autossh.1 "$pkgdir"/usr/share/man/man1/autossh.1
  install -D -m644 "$srcdir"/LICENSE "$pkgdir"/usr/share/licenses/${pkgname}/LICENSE
}
