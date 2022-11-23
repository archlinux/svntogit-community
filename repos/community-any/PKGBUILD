# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: icasdri <icasdri at gmail dot com>
# Contributor: hexchain <i@hexchain.org>

pkgname=mypy
pkgver=0.991
pkgrel=2
pkgdesc='Optional static typing for Python 2 and 3 (PEP484)'
url="http://www.mypy-lang.org/"
arch=('any')
license=('MIT')
depends=('python-psutil' 'python-mypy_extensions' 'python-typing_extensions'
'python-tomli')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')
checkdepends=('python-pytest' 'python-six')
optdepends=(
  'python-lxml: for reports'
  'python-pip: for installing missing types'
)
source=("$pkgname-$pkgver.tar.gz::https://pypi.org/packages/source/m/$pkgname/$pkgname-$pkgver.tar.gz")
sha256sums=('3c0165ba8f354a6d9881809ef29f1a9318a236a6d81c690094c5df32107bde06')

prepare() {
    cd "$pkgname-$pkgver"
    # remove unneeded build requirements as we are not compiling mypy: https://github.com/python/mypy/issues/14171
    sed -e '/typing_extensions/d;/mypy_extensions/d;/typed_ast/d;/tomli/d;/types-psutil/d;/types-setuptools/d;/types-typed-ast/d' -i pyproject.toml
    # -Werror, not even once
    sed -e '/Werror/d' -i mypyc/build.py
}

build() {
    cd "$pkgname-$pkgver"
    python -m build --wheel --no-isolation
}

check() {
    cd "$pkgname-$pkgver"
    pytest -vv -c /dev/null
}

package() {
    local _site_packages=$(python -c "import site; print(site.getsitepackages()[0])")

    cd "$pkgname-$pkgver"
    python -m installer --destdir="$pkgdir" dist/*.whl
    install -vDm644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"
    # remove tests
    rm -frv "$pkgdir/$_site_packages/$pkgname/test/"
}
