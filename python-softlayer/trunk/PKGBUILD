# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-softlayer
pkgver=6.1.4
_commit=0e656572a605dcb5c2f34d0f6a5c13d0589f396e
pkgrel=2
pkgdesc="A library for SoftLayer's API"
arch=('any')
license=('MIT')
url='https://github.com/softlayer/softlayer-python'
depends=('python-six' 'python-prettytable' 'python-click' 'python-requests' 'python-prompt_toolkit'
         'python-pygments' 'python-urllib3' 'python-rich')
makedepends=('git' 'python-setuptools')
checkdepends=('python-pytest' 'python-testtools' 'python-softlayer-zeep' 'tk')
source=("git+https://github.com/softlayer/softlayer-python.git#commit=$_commit")
sha512sums=('SKIP')

prepare() {
  cd softlayer-python
  sed -i 's/==/>=/' setup.py
}

build() {
  cd softlayer-python
  python setup.py build
}

check() {
  cd softlayer-python
  python -m pytest
}

package() {
  cd softlayer-python
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/

  # It's only present when tests are enabled, so adding -f
  local python_version=$(python -c 'import sys; print(".".join(map(str, sys.version_info[:2])))')
  rm -rf "$pkgdir"/usr/lib/python${python_version}/site-packages/tests

  # Prevent collisions with `sl` package; This command is deemed deprecated by
  # the project anyway
  rm -f "$pkgdir/usr/bin/sl"
}

# vim:set ts=2 sw=2 et:
