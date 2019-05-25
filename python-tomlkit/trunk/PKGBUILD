# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tomlkit
pkgver=0.5.3
pkgrel=2
pkgdesc="Style-preserving TOML library for Python"
url="https://github.com/sdispater/tomlkit"
license=('MIT')
arch=('any')
depends=('python')
checkdepends=('python-pytest')
source=("https://pypi.io/packages/source/t/tomlkit/tomlkit-$pkgver.tar.gz")
sha512sums=('90939b380fb8c58a1825c45740d599f116adf5075b1efb327ceb72353b1d1b3d6d6b960ed7673d46af586fc3ed56a866a6a8eb8dfc2a78ea128b5b7f214b0b55')

build() {
  cd tomlkit-$pkgver
  python setup.py build
}

check() {
  cd tomlkit-$pkgver
  # TODO: package a pyproject to setup converter and use git source
  # python -m pytest
}

package() {
  cd tomlkit-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
