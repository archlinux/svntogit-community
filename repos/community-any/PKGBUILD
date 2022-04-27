# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=tomlkit
pkgname=python-tomlkit
pkgver=0.10.2
pkgrel=1
pkgdesc="Style-preserving TOML library for Python"
url="https://github.com/sdispater/tomlkit"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-build'
             'python-installer'
             'python-poetry')
checkdepends=('python-pytest'
              'python-yaml')
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/${_pkgname}/${_pkgname}-${pkgver}.tar.gz")
sha512sums=('e1d5353659f9a0f4ba2f6a0b82980f0b50b012e3b299c2c6b12aa8a63fc4772649bdc2b5a755c21acc46fe2d226241918fb09a4202cca596b6e9633be95e79d8')

build() {
  cd tomlkit-$pkgver
  python -m build -wn
}

check() {
  cd tomlkit-$pkgver
  pytest
}

package() {
  cd tomlkit-$pkgver
  python -m installer -d "$pkgdir" dist/*.whl
  install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
}
