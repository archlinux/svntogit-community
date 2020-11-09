# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=tomlkit
pkgname=python-tomlkit
pkgver=0.7.0
pkgrel=1
pkgdesc="Style-preserving TOML library for Python"
url="https://github.com/sdispater/tomlkit"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-dephell')
checkdepends=('python-pytest' 'python-yaml')
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/${_pkgname}/${_pkgname}-${pkgver}.tar.gz"
        setup.py)
sha512sums=('1483dbc3a8cf87257d592b5af97a66449133337b5a6f709d997054861615527510338fa27f048b27a69611782bd35a126c750eee465301d92e83cd2a8e45c5a5'
            'd427467008174606804715b3f07c53d41132bb198298b2a09bf44c56ddf9bccdfc4354ae2c50ab906367460a5c29ab682519bbe568010dca59017647e1b6efb6')

prepare() {
  cd tomlkit-$pkgver

  # poetry-generated setup.py is badly broken in several ways, including
  # distribution of tests in the built package as well as using distutils for
  # bad metadata. See https://github.com/sdispater/poetry/issues/866
  #dephell deps convert --from pyproject.toml --to setup.py

  # Bootstrapping for Python 3.9
  cp ../setup.py .
}

build() {
  cd tomlkit-$pkgver
  python setup.py build
}

check() {
  cd tomlkit-$pkgver
  python -m pytest
}

package() {
  cd tomlkit-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
