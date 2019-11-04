# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=cachy
pkgbase=python-cachy
pkgname=('python-cachy' 'python2-cachy')
pkgver=0.2.0
# git tags are missing, see https://github.com/sdispater/cachy/issues/4
_commit=ee4b044d6aafa80125730a00b1f679a7bd852b8a
pkgrel=2
pkgdesc="simple yet effective caching library"
arch=('any')
url="https://github.com/sdispater/${_pkgname}"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools' 'python-dephell')
_checkdeps=('flexmock' 'pytest-mock' 'memcached' 'fakeredis')
checkdepends=("${_checkdeps[@]/#/python-}" "${_checkdeps[@]/#/python2-}" 'pifpaf' 'memcached')
source=("${_pkgname}-${_commit}.tar.gz::${url}/archive/${_commit}.tar.gz")
sha256sums=('b25d9ef92903c5f12dd8e28db8fc416a604dd4b11735cc4a0bf848eba6f53ab5')
b2sums=('7ab058d73965b4edaa86fff63de41c061c138b073c3b960ef83433b06018323b731ce2614d45bf105a75dbce454b794066b0d337710c8f3f7fd4f9bfd1bdb607')

prepare() {
    cd "${srcdir}"/${_pkgname}-${_commit}

    # poetry-generated setup.py are fatally broken, see:
    # https://github.com/sdispater/poetry/issues/866
    dephell deps convert --from pyproject.toml --to setup.py
}

build(){
    cd "${srcdir}"/${_pkgname}-${_commit}

    python setup.py build
    python2 setup.py build
}

# Tests pass but only with an old semver major version of redis/fakeredis
# which we do not package.
#check() {
#    cd "${srcdir}"/${_pkgname}-${_commit}
#
#    pifpaf run memcached --port 11211 -- pytest
#    pifpaf run memcached --port 11211 -- pytest2
#}

package_python-cachy() {
    depends=('python')

    cd "${srcdir}"/${_pkgname}-${_commit}
    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}

package_python2-cachy() {
    depends=('python2')

    cd "${srcdir}"/${_pkgname}-${_commit}
    python2 setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
