# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=pipx
pkgname=python-$_pkgname
pkgver=1.2.0
pkgrel=1
pkgdesc='Install and Run Python Applications in Isolated Environments'
arch=('any')
url='https://github.com/pipxproject/pipx'
license=('MIT' 'BSD')
depends=('python' 'python-userpath' 'python-argcomplete' 'python-packaging')
makedepends=('python-build' 'python-installer' 'python-hatchling' 'python-wheel')
#checkdepends=('python-tox' 'python-pytest')
source=("$pkgname-$pkgver.tar.gz::$url/archive/$pkgver.tar.gz")
sha512sums=('3563b986ecb80a57dab6a811f3c9d952f50647b530ceacdb4103bcc16f14b53602040b102830354c3b9a3518e095045a6e3bfd8fc5499cf25b6061d30b19cd6c')

build() {
  cd $_pkgname-$pkgver

  python -m build -nw
}

#check() {
#  cd $_pkgname-$pkgver
#
#  nox
#}

package() {
  cd $_pkgname-$pkgver

  python -m installer -d "$pkgdir" dist/*.whl

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
