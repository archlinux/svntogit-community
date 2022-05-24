# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=tomlkit
pkgname=python-tomlkit
pkgver=0.11.0
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
sha512sums=('2e89748140cfdae217ac3ac999f0b718414d28218d61fb5219adc503ede2ea1f4003be9ef4453f189b0ee86df463c59520244b9fd26553bd4d8047674cba61c9')

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
