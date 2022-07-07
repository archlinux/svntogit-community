# Maintainer: Santiago Torres-Arias <santiago @ usualplace>
# Contributor: Kaizhao Zhang <zhangkaizhao@gmail.com>

pkgname=python-hatchling
pkgver=1.4.1
pkgrel=1
pkgdesc="A modern project, package, and virtual env manager (backend)"
arch=('any')
url="https://github.com/ofek/hatch"
license=('MIT')
depends=('python' 'python-tomli' 'python-packaging' 'python-pathspec'
        'python-pluggy' 'python-editables')
makedepends=('python-pip' 'python-build' 'python-setuptools')

_name=${pkgname/python-/}
source=(
  "${url}/archive/refs/tags/${_name}-v${pkgver}.tar.gz"
)
sha256sums=('8c1fc7ab16e2f2323fcdb8989498b291bbd1daaa6441448f2f9712f8f7fe1292')

build() {
  cd "${srcdir}/hatch-${_name}-v${pkgver}"
  python -m build backend
}

package() {
  cd "${srcdir}/hatch-${_name}-v${pkgver}"

  install -Dm644 README.md "${pkgdir}/usr/share/doc/${pkgname}/README.md"
  install -Dm644 backend/LICENSE.txt "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE.txt"

  PIP_CONFIG_FILE=/dev/null pip install --isolated --root="${pkgdir}" \
            --ignore-installed --no-deps backend/dist/*.whl

}
