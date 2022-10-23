# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Marcel Campello <marcel.campello@prafrentex.com.br>
# Contributor: David Birks <david@birks.dev>

pkgname=aws-cli-v2
pkgver=2.8.5
pkgrel=1
pkgdesc='Unified command line interface for Amazon Web Services (version 2)'
arch=(any)
url='https://github.com/aws/aws-cli/tree/v2'
license=(Apache)
# wcwidth is not used; upstream pinned it due to pyinstaller issues
# https://github.com/aws/aws-cli/pull/5254
depends=(python python-awscrt python-certifi python-colorama python-cryptography python-dateutil
         python-distro python-docutils python-jmespath python-prompt_toolkit python-ruamel-yaml
         python-urllib3)
makedepends=(python-build python-wheel python-flit-core python-installer)
# Tests need the 'ps' binary
checkdepends=(python-pytest python-pytest-xdist python-jsonschema python-mock procps-ng)
provides=(aws-cli)
conflicts=(aws-cli)
source=("$pkgname-$pkgver.tar.gz::https://github.com/aws/aws-cli/archive/$pkgver.tar.gz"
        prompt-toolkit-3.0.29.diff)
sha256sums=('0ca266c345099fd7edea4befddf1bc571e84a21870c5ba0fc5fd7612c04ccc0c'
            'c4f0bfe21bef89934137c57ee4771db57e8dad0f995634ee4de0890dcf45a636')

prepare() {
  cd aws-cli-$pkgver

  # Don't treat warnings as errors
  sed -i '/"error::/d' pyproject.toml

  # See: https://github.com/prompt-toolkit/python-prompt-toolkit/commit/97ac51413f8d412599233fc3da44d4c7fc456f8c
  patch -Np1 -i ../prompt-toolkit-3.0.29.diff
}

build() {
  cd aws-cli-$pkgver

  echo "Generating auto-complete index. Takes a few minutes..."
  PYTHONPATH="$PWD" ./scripts/gen-ac-index --index-location=./awscli/data/ac.index

  python -m build --wheel --no-isolation --skip-dependency-check
}

check() {
  cd aws-cli-$pkgver

  export AWS_SECRET_ACCESS_KEY=fake_key
  export AWS_ACCESS_KEY_ID=fake_id

  export PYTHONPATH="$PWD"

  # --basetemp is for tests/backends
  # Use --dist=loadfile following upstream. The default --dist=load may cause test failures and is not faster
  pytest tests -n auto --dist loadfile --basetemp="$PWD/tmp" --ignore=tests/integration
}

package() {
  cd aws-cli-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm 644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  install -Dm 644 bin/aws_bash_completer "$pkgdir/usr/share/bash-completion/completions/aws"
}
