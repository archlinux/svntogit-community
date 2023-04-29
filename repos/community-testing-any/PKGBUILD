# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=stack_data
pkgname=python-stack-data
pkgver=0.6.2
pkgrel=5
pkgdesc='Extract data from python stack frames and tracebacks for informative displays'
arch=('any')
url=https://github.com/alexmojaki/stack_data
license=('MIT')
depends=('python-asttokens' 'python-executing' 'python-pure-eval')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm'
             'python-wheel')
checkdepends=('cython' 'python-littleutils' 'python-pygments' 'python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz"
        "$pkgname-update_test_pygments_example.patch::$url/commit/4fbe4c0aec04ac818070d5963b0249a5592c1b53.patch"
        '0002-Patch-out-typeguard.patch')
sha256sums=('32d2dd0376772d01b6cb9fc996f3c8b57a357089dec328ed4b6553d037eaf815'
            'e8946290f32855d91d64d4173fd254dceb9c1b6c397393b52e20fdccd867872a'
            '35bd4d2b2227dd045185a9e979c067cfc1828197845633d23d670da59e8133a0')
b2sums=('1344b48a597af3df3a00036412c513faa97824f183a4337566a1a8efafcb6ec6597cf5fad3c6d532e8df2173900bdf87d0071efc66a801bd93743a92619fb5dd'
        'ed6bedb214477fe99448ab7379834c7c49f932c3393d34023839951011279731bf6a310e3848a1ac8706573f2758697f25c4eaaf06aa704f10f1c31df5ac2254'
        '9a996a0ff97930777fffd8f2626c0403098d0d3b211115c132e045b77e5506577aa392b94c3fb285be35a274455ec19eca9d1bf265bd29bc1e2e0cdd6cfb2fe5')

prepare() {
  cd $_name-$pkgver
  patch --forward --strip=1 --input=../$pkgname-update_test_pygments_example.patch

  # Incompatible with typeguard >=3 https://github.com/alexmojaki/stack_data/issues/50
  patch --forward --strip=1 --input=../0002-Patch-out-typeguard.patch
}

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $_name-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python -m pytest
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$_name-$pkgver.dist-info/LICENSE.txt \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.txt
}
