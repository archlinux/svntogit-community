# Maintainer: Santiago Torres-Arias <santiago @ usualplace>
# Contributor: Kaizhao Zhang <zhangkaizhao@gmail.com>

pkgname=python-hatchling
pkgver=0.21.1
pkgrel=1
pkgdesc="A modern project, package, and virtual env manager (backend)"
arch=('any')
url="https://github.com/ofek/hatch"
license=('MIT' 'Apache')
depends=('python')
makedepends=('python-pip' 'python-build' 'python-setuptools')

_name=${pkgname/python-/}
source=(
  "${url}/archive/refs/tags/${_name}-v${pkgver}.tar.gz"
)
sha256sums=('2710295e42dee07552ffa28eb1c1902bbff58a9ad6f883c357b41373b69782db')

build() {
  cd "${srcdir}/hatch-${_name}-v${pkgver}"
  python -m build backend
}

package() {
  cd "${srcdir}/hatch-${_name}-v${pkgver}"

  PIP_CONFIG_FILE=/dev/null pip install --isolated --root="${pkgdir}" \
            --ignore-installed --no-deps backend/dist/*.whl

}
