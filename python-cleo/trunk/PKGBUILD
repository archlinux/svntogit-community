# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=cleo
pkgname=python-cleo
pkgver=1.0.0a5
pkgrel=2
pkgdesc="create beautiful and testable command-line interfaces"
arch=(any)
url="https://github.com/python-poetry/$_pkgname"
license=(MIT)
depends=(python-crashtest python-pylev)
makedepends=(python-build python-installer python-poetry-core python-wheel)
checkdepends=(python-pytest python-pytest-mock)
source=($_pkgname-$pkgver.tar.gz::$url/archive/$pkgver.tar.gz)
sha256sums=('b75424b2c3f71dec06342290b255d725a4c02f83f3baa98b0a805162f09515da')
b2sums=('351ae54e6068fd76233934316ffe65eb4394d59115b0c1f3a96ba1e587245b08399c7d7c784562dd97baa7ebcbce227e780269f2b13a6922bb05e3eb29d764c3')

prepare() {
    # we do not use overly strict version constraints
    sed 's/\^/>=/g' -i $_pkgname-$pkgver/pyproject.toml
}

build(){
    cd $_pkgname-$pkgver
    python -m build --wheel --no-isolation
}

check() {
    cd $_pkgname-$pkgver
    pytest -vv
}

package() {
    cd $_pkgname-$pkgver
    python -m installer --destdir="$pkgdir" dist/*.whl
    install -vDm 644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
