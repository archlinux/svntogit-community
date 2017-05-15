# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Jan Koppe <post@jankoppe.de>

pkgname=yarn
pkgver=0.24.3
pkgrel=1
pkgdesc='Fast, reliable, and secure dependency management'
arch=(any)
url='http://yarnpkg.com'
license=('BSD')
depends=('nodejs')
source=("https://github.com/yarnpkg/yarn/releases/download/v$pkgver/yarn-v$pkgver.tar.gz")
sha512sums=('da55ee878ebd07ff7252a498678917bc52b52581c2de8b4add2f49536c4ce83a9c73b01c70edb54145c1c16d83ba9180700a6bb53951724ff69b1f259fa16bcd')

package() {
  install -dm755  "$pkgdir"/usr/lib/node_modules/yarn
  cp -R "$srcdir"/dist/* "$pkgdir"/usr/lib/node_modules/yarn

  install -dm755 "$pkgdir"/usr/bin
  ln -s /usr/lib/node_modules/yarn/bin/yarn.js "$pkgdir"/usr/bin/yarn
  ln -s /usr/lib/node_modules/yarn/bin/yarn.js "$pkgdir"/usr/bin/yarnpkg

  install -Dm644 "$srcdir"/dist/LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
